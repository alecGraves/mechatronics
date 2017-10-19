%% Part 1: black out the image
im = imread('image.png');
imshow(im); axis on;

% get the equation of line defined by clicks:
[c1] = ginput(1);
[c2] = ginput(1);
coefficients = polyfit([c2(1) c1(1)], [c2(2) c1(2)], 1);
m = coefficients(1);
b  = coefficients(2);

s = size(im); % get the size of the image
[y, x] = meshgrid(1:s(1), 1:s(2));
mask = double(y >= m*x + b);

im2 = uint8(double(im) .* mask.');
imshow(im2); axis on;
waitforbuttonpress;

%% Part 2: Display the image
imshow(im); axis on;
[c11] = ginput(1);
[c22] = ginput(1);
[c3] = ginput(1);
[c4] = ginput(1);

clicks = {c11 c22 c3 c4};

segmentedImage = im;
for i = 1:4
    c1 = clicks{i};
    c2 = clicks{mod(i, 4) + 1};
    coefficients = polyfit([c2(1) c1(1)], [c2(2) c1(2)], 1);
    m = coefficients(1);
    b  = coefficients(2);
    if i <= 2
        mask = double(y >= m.*x + b);
    else
        mask = double(y <= m.*x + b);
    end
    segmentedImage = uint8(double(segmentedImage) .* mask.');
%     imshow(segmentedImage);
%     waitforbuttonpress;

end

imshow(segmentedImage); axis on;

%% Part 3: Show histogram
figure(3);
image = segmentedImage;

image  = double(reshape(image,[],3));
size(image);
scale = 1:max(image(:));

subplot(3, 1, 1);
hist(image(:,1), scale);
axis([1,255, 0, 200]);
h = findobj(gca,'Type','patch');
h.FaceColor = [1 0 0];

subplot(3, 1, 2);
hist(image(:,2), scale);
axis([1,255, 0, 200]);
h = findobj(gca,'Type','patch');
h.FaceColor = [0 1 0];

subplot(3, 1, 3);
 hist(image(:,3), scale);
axis([1,255, 0, 200]);
h = findobj(gca,'Type','patch');
h.FaceColor = [0 0 1];


%% Part 4: 
disp('click on 5 folders')
figure(1); imshow(im); axis on;
% range = int32([25; 25; 25]);
% masks = zeros([5 3 2]);
br = [40 80 100; 80 115 150];
yr = [30 30 30; 70 70 50];
gr = [80 100 170; 110 130 200];
or = [240 130 75; 255 150 100];
vr = [120 80 150; 140 110 180];

for i = 1:1000
    c = int32(ginput(1));
    colors = im(c(1), c(2), :);
    colors = int32(colors(:)).'
%     masks(i, :, 1) = max(min(colors - range, 255), 0);
%     masks(i, :, 2) =  max(min(colors + range, 255), 0);
    br(1, :)
    if colors > br(1, :) & colors < br(2, :)
        disp("blue folder");
%         break;
    end
    if colors > yr(1, :) & colors < yr(2, :)
        disp("yellow folder");
%         break;
    end
    if colors > gr(1, :) & colors < gr(2, :)
        disp("green folder");
%         break;
    end
    if colors > or(1, :) & colors < or(2, :)
        disp("orange folder");
%         break;
    end
    if colors > vr(1, :) & colors < vr(2, :)
        disp("violet folder");
%         break;
    end
end


% for i = 1:5
%     m = masks(i, :, 1);
%     m = reshape(m, 1, 1, 3);
%     M = masks(i, :, 2);
%     M = reshape(M, 1, 1, 3);
%     mask = im > m & im < M;
%     filtered = im .* uint8(mask);
% 
%     figure(1); imshow(uint8(mask).*255)
%     waitforbuttonpress;
% end
