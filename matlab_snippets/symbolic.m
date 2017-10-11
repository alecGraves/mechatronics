%% random symbolic computations
% created by Alec Graves
syms x y
y = sin(x);
fplot(y, [0, 2*pi]);
%% plot a cubic funct
y= x^3 + 167;
fplot(y);
%% evaluate a limit
limit(y, x, Inf)% lim_x->Inf (y)
%% undo a transfer function
% [A, B, C, D] = tf2ss()
%% plot of neural net activation function
clear
syms z u x v y b
z = 1/(1 + exp(-1*(u*x  + v*y + b)));
z
pretty(z)
ddx = diff(z, x);
b = 2; u = -3; y = -2; v = 6;
a = subs(z);
y = diff(a, x)
fplot(a);
hold on
fplot(y);


