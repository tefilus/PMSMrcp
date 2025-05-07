%rtiver rti1005;
%addpath(strcat(pwd,'\ASM_ElectricComponents_lib_DEV\MATLAB\ASM\Libraries'))
%addpath(strcat(pwd,'\ASM_ElectricComponents_lib_DEV\MATLAB\ASM\MFcns'))
%addpath(strcat(pwd,'\ASM_ElectricComponents_lib_DEV\MATLAB\Local'))

% Clear Workspace
%clear all;

SIM.StepSize.v = 5e-6;  % Step Size for plant simulation
T_PWM          = 50e-6; % PWM periode = Controller step size   
SIM.ControllerStepSize.v = 50e-6;
SIM.MDLStepSize.v        = 5e-6;
SIM.StepSize.v = SIM.MDLStepSize.v;
%==========================================================================
%   Set your Machine parameters in the following area!
%==========================================================================

    L         = 0.4e-3;                 %Stator inductance 
    R         = 0.2;                    %Stator resistance 
    Psi       = 0.017;                  %Flux induced by magnet Psi 
    PolePairs = 4.0;                    %PolePairs    
    Km        = 1.5*Psi*PolePairs;      %1.5*Psi*Pp 
    UD        = 15.0;                   %DC link voltage  
    IQ_MAX    = 10.6;                    %maximal value of i_q (ADAPT !!) 
    N_MAX     = 3000.0;                 %max. mechanical velocity (ADAPT !!)
    ID_MAX    = 5.6;                    %maximal value of i_d  (maxFieldWeaking Current)  

%==========================================================================
%   Controller settings
%==========================================================================


f_Filter_n = 150;
f_Filter_i = 2000;
TF_n      = 1/(2 * pi * f_Filter_n);  %Filter time constant for n
TF_i      = 1/(2 * pi * f_Filter_i);  %Filter time constant for id,iq
T_sum     = T_PWM + TF_i;             %Inverter dead time + measurement delay

J_sum     = 4.675e-4;                 %Inertia Sum
T_stator  = L / R;                    %Stator time constant

%==========================================================================
%   Currentcontroller (symmetric optimum) G(s) = Kp + 1/(s*Tn)
%==========================================================================
KP_i      = (0.5*(T_stator / T_sum) * (1+T_sum^2/T_stator^2) * R);                %P-contribution CurrentController
TN_i      = 1*(4*T_sum*(1+T_sum^2/T_stator^2)/(1+T_sum/T_stator)^3);              %reset time CurrentController
KI_i      = (KP_i/TN_i);                                               %I-contribution CurrentController

TEI=(1+R/KP_i)*TN_i + TF_n; 

%==========================================================================
% Speedcontroller (symmetric optimum) G(s) = Kp + 1/(s*Tn)
%==========================================================================
KP_n = (0.5*J_sum/(2*TEI)*(1/(3/2*PolePairs*Psi))*2*pi/60);
TN_n = TEI;
KI_n = (KP_n/TN_n);

%==========================================================================
%   Parameters for the PMSM Controller
%==========================================================================
SIM.StepSize.v                       = 50e-6;

%CPT.MDL_SW.SoftECU_Ctrl_mode_SW.v    = 3; %['1n_ctrl|2i_ctrl|3v_ctrl']
PMSM_Ctrl_Ctrl_mode_SW   = 3; %['1n_ctrl|2i_ctrl|3v_ctrl']

CPT.MDL_PAR.Mechanics_Ineria_Load.v  = 0;
CPT.MDL_PAR.Mechanics_Trq_Load.v     = 0.5;


%CPT.MDL_PAR.SoftECU_n_Limit.v        = N_MAX;
PMSM_Ctrl_n_Limit        = N_MAX;

%CPT.MDL_PAR.SoftECU_n_Set.v          = 100;
PMSM_Ctrl_n_Set          = 0;

%CPT.MDL_PAR.SoftECU_i_d_Set.v        = 0;
PMSM_Ctrl_i_d_Set        = 0;

%CPT.MDL_PAR.SoftECU_i_q_Set.v        = 0;
PMSM_Ctrl_i_q_Set        = 0;

%CPT.MDL_PAR.SoftECU_v_d_Set.v        = 0;
PMSM_Ctrl_v_d_Set        = 0;

%CPT.MDL_PAR.SoftECU_v_q_Set.v        = 0;
PMSM_Ctrl_v_q_Set        = 0;

%CPT.MDL_PAR.SoftECU_fRS_Set.v        = 0;
PMSM_Ctrl_fRS_Set        = 0;

%CPT.MDL_PAR.SoftECU_n_Stroke.v       = 0;
PMSM_Ctrl_n_Stroke=0;

%CPT.MDL_PAR.SoftECU_i_d_Stroke.v     = 0; 
PMSM_Ctrl_i_d_Stroke =0;

%CPT.MDL_PAR.SoftECU_i_q_Stroke.v     = 0;
PMSM_Ctrl_i_q_Stroke = 0;

%CPT.MDL_PAR.SoftECU_load_torque.v    = 0;
PMSM_Ctrl_load_torque = 0;

%CPT.MDL_PAR.SoftECU_theta_offset.v   = 0.5;
PMSM_Ctrl_theta_offset   = 0.5;   

CPT.MDL_PAR.SoftECU_UBatt.v          = UD;

%CPT.MDL_PAR.SoftECU_V_DCLink_Limit.v = UD;
PMSM_Ctrl_V_DCLink_Limit = UD;


%CPT.MDL_PAR.SoftECU_Kp_id.v          = KP_i;
PMSM_Ctrl_Kp_id          = KP_i;

%CPT.MDL_PAR.SoftECU_Ki_id.v          = KI_i;
PMSM_Ctrl_Ki_id          = KI_i;

%CPT.MDL_PAR.SoftECU_Kp_iq.v          = KP_i;
PMSM_Ctrl_Kp_iq          = KP_i;

%CPT.MDL_PAR.SoftECU_Ki_iq.v          = KI_i;
PMSM_Ctrl_Ki_iq          = KI_i;

%CPT.MDL_PAR.SoftECU_Kp_n.v           = KP_n;
PMSM_Ctrl_Kp_n           = KP_n;

%CPT.MDL_PAR.SoftECU_Ki_n.v           = KI_n;
PMSM_Ctrl_Ki_n           = KI_n;

%CPT.MDL_PAR.SoftECU_Limit_iq.v       = IQ_MAX;
PMSM_Ctrl_Limit_iq       = IQ_MAX;

%CPT.MDL_PAR.SoftECU_TF_Id.v          = TF_i;
PMSM_Ctrl_TF_Id = TF_i;

%CPT.MDL_PAR.SoftECU_TF_Iq.v          = TF_i;
PMSM_Ctrl_TF_Iq = TF_i;

%CPT.MDL_PAR.SoftECU_TF_n.v           = TF_n;
PMSM_Ctrl_TF_n = TF_n;

CPT.MDL_PAR.SoftECU_f_Filter_i.v     = f_Filter_i;
CPT.MDL_PAR.SoftECU_f_Filter_n.v     = f_Filter_n;
CPT.MDL_PAR.SoftECU_Ls.v             = L;
CPT.MDL_PAR.SoftECU_Psi_p.v          = Psi;

%CPT.MDL_PAR.SoftECU_Vel_Src.v        = 1;
PMSM_Ctrl_Vel_Src = 4;

%CPT.MDL_PAR.SoftECU_Pos_Src.v        = 2;
PMSM_Ctrl_Pos_Src = 1;

% Machine parameters need for controller
%--------------------------------------------------------------------------
% Pole pairs
Const_PolePairs = PolePairs;
% Flux induced by magnet Psi [Wb]
Const_Psi = Psi;
% Stator inductance in direct axis Lsd [H]
Const_Ld_Stator = L;
% Stator inductance in quadrature axis Lsq [H]
Const_Lq_Stator = L;
% Fieldweakening current [A]
Const_Id_Fieldweakening = 0;
% Switch Fieldweaking on or off [1off|2on]
SW_Fieldweakening = 2;

%Parameters for the LUST load machine
%----------------------------------------------------------------------
load_machine_ctrl = 0;  %-1 fully load dir 0; 1=fully load dir 1

% MDL.ElectricComponents.Controller.PMSM_Controller.Const_PolePairs.Author = 'dSPACE';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_PolePairs.Origin = 'standard';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_PolePairs.Version = '1.0';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_PolePairs.LastModified = '12.12.2007';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_PolePairs.Comment = 'Pole pairs ';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_PolePairs.vName = 'Const_PolePair';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_PolePairs.vUnit = '[]';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_PolePairs.v = PolePairs;

% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Psi.Author = 'dSPACE';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Psi.Origin = 'standard';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Psi.Version = '1.0';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Psi.LastModified = '12.12.2007';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Psi.Comment = 'Flux induced by magnet Psi';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Psi.vName = 'Const_Psi';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Psi.vUnit = '[Wb]';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Psi.v = Psi;

% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Ld_Stator.Author = 'dSPACE';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Ld_Stator.Origin = 'standard';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Ld_Stator.Version = '1.0';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Ld_Stator.LastModified = '12.12.2007';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Ld_Stator.Comment = 'Stator inductance in direct axis Lsd ';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Ld_Stator.vName = 'Const_Ld';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Ld_Stator.vUnit = '[H]';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Ld_Stator.v = L;

% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Lq_Stator.Author = 'dSPACE';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Lq_Stator.Origin = 'standard';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Lq_Stator.Version = '1.0';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Lq_Stator.LastModified = '12.12.2007';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Lq_Stator.Comment = 'Stator inductance in quadrature axis Lsq ';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Lq_Stator.vName = 'Const_Lq';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Lq_Stator.vUnit = '[H]';
% MDL.ElectricComponents.Controller.PMSM_Controller.Const_Lq_Stator.v = L;

