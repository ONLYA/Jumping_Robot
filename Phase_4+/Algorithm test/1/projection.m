u0 = 1; v0 = 1; %principle point (u0, v0)
alpha = 1;  %scaling factor along u axis
beta = 1;   %scaling factor along v axis
gamma = 1;  %skewness between u and v axes
%define camera intrinsic matrix
A = [alpha gamma u0;
       0   beta  v0;
       0     0    1];
%define 3x3 rotation matrix
R = [1 0 0;
     0 1 0;
     0 0 1];
%define 1x3 translation column vector
T = [1;
     1;
     1];
%define projection matrix P
P = A.*[R T;0 0 0 1];
