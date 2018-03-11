%% Hello, This is the matlab part of the final.
% Code by Team Red
%% Problem 4
disp('This is problem 4.')
x1 = 0;
x = 20;
while abs(x-x1) > 1e-8
 x1 = x;
 x = atan(1.2/(0.6+1.8*sin(x)+0.4*tan(x)));
end
disp(['Final x = ' num2str(x)]);

% Problem 3
clear;
[x,y] = meshgrid(linspace(-1, 1,2000), linspace(-1, 1,2000)); 
y(abs(y.^2)>(1-x.^2)) = NaN;
z = exp(1/10./(x+y).^2);
z(z>10)=NaN;
figure(1); clf;
surf(x,y,z);
shading interp;
