%rtiver rti1005;
%addpath(strcat(pwd,'\ASM_ElectricComponents_lib_DEV\MATLAB\ASM\Libraries'))
%addpath(strcat(pwd,'\ASM_ElectricComponents_lib_DEV\MATLAB\ASM\MFcns'))
%addpath(strcat(pwd,'\ASM_ElectricComponents_lib_DEV\MATLAB\Local'))

% Clear Workspace
%clear all;


T_PWM          = 50e-6; % PWM periode = Controller step size        
SIM.ControllerStepSize.v = 50e-6;
SIM.MDLStepSize.v        =  5e-6;
SIM.StepSize.v = SIM.MDLStepSize.v; %Step Size for plant simulation
%==========================================================================
%   Set your Machine parameters in the following area!
%==========================================================================

    % Elmo BLDC Motor
    L         = 0.4e-3;                 %Stator inductance 
    R         = 0.2;                    %Stator resistance 
    Psi       = 0.017;                  %Flux induced by magnet Psi 
    PolePairs = 4.0;                    %PolePairs    
    Km        = 2*Psi*PolePairs;        %2*Psi*Pp 
    UD        = 15.0;                   %DC link voltage  
    IA_MAX    = 9.5;                    %maximal value of iA 
    N_MAX     = 3000.0;                 %max. mechanical velocity
        
    % Back EMF of BLDC Motor
    epsRS     = [ 0   30   60   90  120  150  180  210  240  270  300  330  360];
    BackEMF_a = [ 1    1    1    1    1    0   -1   -1   -1   -1   -1    0    1];
    BackEMF_b = [-1   -1   -1    0    1    1    1    1    1    0   -1   -1   -1]; 
    BackEMF_c = [ 1    0   -1   -1   -1   -1   -1    0    1    1    1    1    1]; 
    psi_angle_basis = epsRS;
    % Sector     1  2  3  4  5  6
    Hall   = [   1  1  1  0  0  0; % Hall_A
                 0  0  1  1  1  0; % Hall_B
                 1  0  0  0  1  1];% Hall_C






    % Truthtable (is_index indicates the actual phase current, which commutates to 0A 
    % in the next sector; is_Dir is 1 for +/- and 0 for -/+)  
    % Hall A,B,C   Za_HSD,Zb_HSD,Zc_HSD     Za_LSD,Zb_LSD,Zc_LSD     is_index   is_DIR
    Zi_HSD_LSD = ...
    [0 0 0           0      0      0          0      0      0          0 0 0      0;    % non existing state
     0 0 1           0      0      1          0      1      0          0 0 1      1;
     0 1 0           0      1      0          1      0      0          0 1 0      1;    
     0 1 1           0      0      1          1      0      0          1 0 0      0;    
     1 0 0           1      0      0          0      0      1          1 0 0      1;    
     1 0 1           1      0      0          0      1      0          0 1 0      0;    
     1 1 0           0      1      0          0      0      1          0 0 1      0;   
     1 1 1           0      0      0          0      0      0          0 0 0      0];   % non existing state
 
 
 
 
 
 
 
     is_index = Zi_HSD_LSD(:,10:12);
     is_dir   = Zi_HSD_LSD(:,13);
     
         

%==========================================================================
%   Controller settings
%==========================================================================
TF_n      = 1/(2 * pi * 100);   %Filter time constant for n %Änderung Jan
TF_iA     = 1/(2 * pi * 2000);  %Filter time constant for iz
T_sum     = T_PWM + TF_iA;      %Inverter dead time + measurement delay
J_sum     = 4.675e-4;           %Inertia Sum
T_stator  = L / R;              %Stator time constant


%==========================================================================
%   Currentcontroller (symmetric optimum) G(s) = Kp + 1/(s*Tn)
%==========================================================================
% compared to DC or PMSM motor R = 2*R has to be used ! T=L/R is still
% valid !
alpha = 2;

KP_i      = (1/alpha) *(T_stator / T_sum) * (1+T_sum^2/T_stator^2) * R*2 ;        %P-contribution CurrentController
TN_i      = (alpha^2) * T_sum * (1+T_sum^2/T_stator^2)/(1+T_sum/T_stator)^3;     %reset time CurrentController
KI_i      = (KP_i/TN_i);                                                           %I-contribution CurrentController
TEI       = (1+R/KP_i)*TN_i + TF_n; 

%==========================================================================
% Speedcontroller (symmetric optimum) G(s) = Kp + 1/(s*Tn)
%==========================================================================
alpha = 2; %(symm. optimum is 2)
KP_n  = J_sum/(alpha*TEI)*(1/(2*PolePairs*Psi))*2*pi/60;
TN_n  = alpha^2*TEI;
KI_n  = (KP_n/TN_n);

%==========================================================================
%   Parameters for the BLDC Controller
%==========================================================================

%%SoftEcu mit BLCD_Ctrl ersetzt. Änderung JanF

%CPT.MDL_SW.SoftECU_Ctrl_mode_SW.v    = 3; %['1n_ctrl|2i_ctrl|3v_ctrl']
BLDC_Ctrl_Ctrl_mode_SW   = 3; %['1n_ctrl|2i_ctrl|3v_ctrl']

CPT.MDL_PAR.Mechanics_Ineria_Load.v  = 0;
CPT.MDL_PAR.Mechanics_Trq_Load.v     = 0.5;

%CPT.MDL_PAR.SoftECU_n_Limit.v        = N_MAX;
BLDC_Ctrl_n_Limit = N_MAX;

%CPT.MDL_PAR.SoftECU_n_Set.v          = 100;
BLDC_Ctrl_n_Set          = 0;

%CPT.MDL_PAR.SoftECU_iA_Set.v         = 1;
BLDC_Ctrl_iA_Set         = 0;

%CPT.MDL_PAR.SoftECU_v_Set.v          = 0;
BLDC_Ctrl_v_Set          = 0;

%CPT.MDL_PAR.SoftECU_iA_Stroke.v      = 0;
%CPT.MDL_PAR.SoftECU_n_Stroke.v       = 0;
BLDC_Ctrl_iA_Stroke = 0;
BLDC_Ctrl_n_Stroke = 0;

CPT.MDL_PAR.SoftECU_UBatt.v          = UD;
%CPT.MDL_PAR.SoftECU_Kp_iA.v          = KP_i;
BLDC_Ctrl_Kp_iA          = KP_i;

%CPT.MDL_PAR.SoftECU_Ki_iA.v          = KI_i;
BLDC_Ctrl_Ki_iA          = KI_i;

%CPT.MDL_PAR.SoftECU_Kp_n.v           = KP_n;
BLDC_Ctrl_Kp_n           = KP_n;

%CPT.MDL_PAR.SoftECU_Ki_n.v           = KI_n;
BLDC_Ctrl_Ki_n           = KI_n;

%CPT.MDL_PAR.SoftECU_Limit_iA.v       = IA_MAX;
BLDC_Ctrl_Limit_iA       = IA_MAX;

%CPT.MDL_PAR.SoftECU_TF_iA.v          = TF_iA;
BLDC_Ctrl_TF_iA          = TF_iA;

%CPT.MDL_PAR.SoftECU_TF_n.v           = TF_n;
BLDC_Ctrl_TF_n = TF_n;

%CPT.MDL_PAR.SoftECU_Vel_Src.v        = 1;
BLDC_Ctrl_Vel_Src = 3;

%==========================================================================
%   Parameters for the Modulator
%==========================================================================
% Indicator matrix for phase current, which commutates to 0 A in the next sector
BLDC_Ctrl_is_index = is_index;

% Indicator vector for direction of phase current (1 for +/- and 0 for -/+)
BLDC_Ctrl_is_dir = is_dir;

% Truth table for gate driver signals depending on Hall
Modulator_Zi_HSD = Zi_HSD_LSD(:,4:6);  
Modulator_Zi_LSD = Zi_HSD_LSD(:,7:9);




% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.Zi_HSD_LSD.Author = 'dSPACE';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.Zi_HSD_LSD.Origin = 'standard';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.Zi_HSD_LSD.Version = '1.0';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.Zi_HSD_LSD.LastModified = '12.12.2007';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.Zi_HSD_LSD.Comment = 'Truth table for gate driver signals depending on Hall';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.Zi_HSD_LSD.vName = 'Zi_HSD_LSD';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.Zi_HSD_LSD.vUnit = '[]';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.Zi_HSD_LSD.v = Zi_HSD_LSD;

% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_index.Author = 'dSPACE';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_index.Origin = 'standard';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_index.Version = '1.0';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_index.LastModified = '12.12.2007';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_index.Comment = 'Indicator matrix for phase current, which commutates to 0 A in the next sector';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_index.vName = 'is_index';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_index.vUnit = '[]';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_index.v = is_index;

% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_dir.Author = 'dSPACE';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_dir.Origin = 'standard';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_dir.Version = '1.0';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_dir.LastModified = '12.12.2007';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_dir.Comment = 'Indicator vector for direction of phase current (1 for +/- and 0 for -/+)';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_dir.vName = 'is_dir';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_dir.vUnit = '[]';
% MDL.ElectricComponents.Machines.BrushlessDCMachine_BLDC.Modulator.is_dir.v = is_dir;

