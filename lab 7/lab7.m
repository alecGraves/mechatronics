% Part 1 - Lab 7
%25 points: Adjust Sensitivity, EdgeThreshold, 
% and radii range to detect all four balls in im30.mat
clear;

% Displays frame 30 of the video
vid = VideoReader('wiffleBalls.mov');
numFrames = vid.NumberOfFrames;
n=numFrames;
im = uint8(zeros(480, 640, 3, n));

for i = 1:n
    frames = read(vid,i); %#ok<VIDREAD>
    im(:, :, :, i) = frames; %#ok<SAGROW>
end


figure(2); clf; 
imshow(im(:, :, :, 30));
hold on; axis on;
ft = 203;

[c, r] = imfindcircles(im(:, :, :, 30), [20 50], 'Sensitivity', .865, 'EdgeThreshold', .05);
viscircles(c,r);


%% Part 2
%25 points: Display the distance matrix 
% and largest and smallest distances between any two balls in im30.mat

distances = zeros(4,4);

for i = 1:4
    distances(i,1) =(sqrt((c(i,2)-c(1,2))^2+(c(i,1)-c(1,1))^2))/ft;
    distances(i,2) =(sqrt((c(i,2)-c(2,2))^2+(c(i,1)-c(2,1))^2))/ft;
    distances(i,3) =(sqrt((c(i,2)-c(3,2))^2+(c(i,1)-c(3,1))^2))/ft;
    distances(i,4) =(sqrt((c(i,2)-c(4,2))^2+(c(i,1)-c(4,1))^2))/ft;
end

distances

for i = 1:4
    disp({'ball ', i})
    [closest_distance, closest_ball] = min(distances(i, :))
    [furthest_distance, furthest_ball] = max(distances(i, :))
end

%% Part 3
%25 points: Loop through frames in wiffleBalls.mov, 
% with exactly the four balls detected in every frame
count = 0;
centers = zeros(4, 2, n);
radii = zeros(4, n);
for i = 1:n
    [c, r] = imfindcircles(im(:, :, :, i), [20 50], 'Sensitivity', .885, 'EdgeThreshold', .05);
    siz = size(c)
    if siz(1) == 4
        count = count+1
        centers(:, :, i) = c;
        radii(:, i) = r;
    end
end

count
n

%% Part 4
%25 points: Plot estimated speed of the moving ball over time
speeds  = zeros(4, n-1);
for j = 1:(n-1)
    distances = zeros(4,4);
    c = centers(:,:,j);
    c2 = centers(:,:,j+1);
    for i = 1:4
        distances(i,1) =(sqrt( (c2(i,2)-c(1,2))^2+(c2(i,1)-c(1,1))^2) )/ft;
        distances(i,2) =(sqrt( (c2(i,2)-c(2,2))^2+(c2(i,1)-c(2,1))^2) )/ft;
        distances(i,3) =(sqrt( (c2(i,2)-c(3,2))^2+(c2(i,1)-c(3,1))^2) )/ft;
        distances(i,4) =(sqrt( (c2(i,2)-c(4,2))^2+(c2(i,1)-c(4,1))^2) )/ft;
    end
    transitions = zeros(1, 4);
    for i = 1:4
        [transitions(i), ~] = min(distances(i, :)); % get distance from closest ball
    end
    speeds(:, j) = transitions/(vid.Duration/n);
end
% speeds

% times = vid.Duration/n
x = linspace(0, vid.Duration, n-1);

hold on
% scatter(x, speeds(1, :), 'X');
% line(x,y);
plot(x,  max(speeds), '-o');

%% Part 3 visualized
% for actual points

for i = 1:n
    clf
    imshow(im(:, :, :, i));
    hold on;
    viscircles(centers(:,:, i),radii(:, i));
    waitforbuttonpress;
end