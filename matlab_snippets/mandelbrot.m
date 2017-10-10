% [x z] = meshgrid(0:20);
% y = zeros(size(x));
% surf(x,y,z);
% xlabel('x');
% hold on;
% surf(x, y+1,z);
% set(gca,'YLim',[-2 2]);
% shading flat;
% camproj perspective;
% campos([5 0.5 50]);
% camtarget([15 0.5 10]);

n = 1000;
m = -1.5;
M = 1.5;

z = complex(zeros(n));
[x, y] = meshgrid(linspace(m, M, n),...
    linspace(m, M, n) );
c = complex(x, y);

image = zeros(n);

tic
for i = 1:100
    disp({'iteration', i})
    z = z.^2 + c;
    image = image + (z.^2 <  4);
end
toc

% disp(sum(sum(image)));
% disp(image);
% g = heatmap(image);
g = surf(x, y, image);
set(g, 'edgecolor','none')

data = gallery('invhess',20);
% disp(data)
colorbar
xlabel('Real'), ylabel('Imaginary'), zlabel('Mandelbrot')