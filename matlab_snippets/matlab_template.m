clc
clear
y = 0:0.001:2*pi;
s = sin(y);
%disp(s);
plot(y, s);

a = sortInc(2, 1, 3);
disp(a);

function [a] = sortInc(a, b, c)
    a = sort([a, b, c]);
end
