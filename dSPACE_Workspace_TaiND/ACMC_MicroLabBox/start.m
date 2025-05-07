% startup script for AC-Motor_Control Demo
% Usage: start
% 20.02.2008 
% dSPACE GmbH
% $Workfile: 
% $Archive: 
% author:   J. Foht, dSPACE GmbH
% date:     20-02-2008
	

%***********************************************************
% cleanup everything before loading the demo
%***********************************************************
clear all; close all;
if ~strcmp(rtitype,'RTI1202') 
    rti1202; %MicroLabBox%
end

disp('running startup script ...');


%***********************************************************
% change to folder where start.m is located (for restart)
%***********************************************************
[folder,f,e] = fileparts(which('start.m'));
cd(folder);


%***********************************************************
% select model from dialog
%***********************************************************
info = sprintf(['\n'...
      'The following models are available:\n'...
      '-------------------------------------------------------------------\n'...
      'BLDC Demo  - This model is a demo for usage of the DS1512 + DS1553 in controlling \n'...
      '              a BLDC motor with Hall Sensors in block commutation mode.\n\n'...
      'PMSM Demo  - This model is  a demo for usage of the DS1512 + DS1553 in controlling \n'...      
      '             a PMSM (permanent magnet synchronous motor) with field oriented \n'...
      '             control (foc) (sine commutation)\n\n'...
      'BLDC Simulation  - Offline Simulation of BLDC Control (block commutation) with \n'...
      '             ASM electric components library \n\n'...
      'PMSM Simulation  - Offline Simulation of PMSM Control (sine commutation) with \n'...
      '             ASM electric components library\n\n'...

]);
%buttons = {'BLDC_Demo','PMSM_Demo','BLDC_ASM_Sim','PMSM_ASM_Sim'};
%fprintf(''); drawnow; pause(0);
%model = ds_msgbox( ...
%   'Message',           info, ...
%   'Title',             'Select a demo' , ...
%   'Button',            buttons, ...
%   'Default',           'BLDC_Demo');
%clear buttons info
title   = 'ACMC'                  ;
qstring = 'Please Select a demo'  ;
str1    = 'BLDC_Demo'             ;
str2    = 'PMSM_Demo'             ;
default =  str1                   ;
model = questdlg(qstring,title,str1,str2,default); 

%***********************************************************
% set search path
%***********************************************************
disp('    adding folders to MATLAB search path ...');
addDirs = { [pwd],...
%            [pwd '\AC_Motor_Solution'], ...
%            [pwd '\AC_Motor_Solution\GUIs'], ...
%            [pwd '\DSMSU'], ...
%            [pwd '\ASM_lib'], ...
            };
for idx_aD=1:length(addDirs)
    addpath(addDirs{idx_aD});
    disp(['        - ' addDirs{idx_aD}]);
end
disp('    ... done!');



%***********************************************************
% change to selected model directory
%***********************************************************
cd(model);
% add model dir to path (switching to Work folder later on)
addpath(pwd);

if ~isempty(model)
    disp (' ');
    disp (['Working directory is ' pwd]);
    disp (' ');
    disp (['Loading model "' model '" ...']);
    disp (' ');
   
    %***********************************************************
    % load parameter files
    %***********************************************************
    % read initialization files for Egas, IO, ASM
    disp('    reading ini-files ...');
    
    % load all relevant controller parameters
    disp('    loading controller parameters  ...');
    eval([model '_ini']);
    disp('    ... done!');

   
   
    %***********************************************************
    % load model
    %***********************************************************
    try
        % open_system('MABXII_ACMotor_Library');    
        open_system(model);
    catch
        disp('Could not open model');    
    end

    % switch to Work folder
    if exist('Work','dir')
        cd('Work');
    end
        
end

disp('... done!');
