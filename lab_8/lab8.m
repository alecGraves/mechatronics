%% Connect to arduino
a = arduino()
%%

data = randi(5, 1, 100);

x = 1:100;

 handles.hPlot = plot(NaN,NaN); % creates the graphics object with no data
 xdata = [get(handles.hPlot,'XData') handles.T(end)];
 ydata = [get(handles.hPlot,'YData') handles.array(end)];    
 set(handles.hPlot,'XData',xdata,'YData',data);
 
while 1
data = [data(2:end) randi(5)];
refreshdata;
end

% save('file', 'data')

%%
% regression for linearizing range data (values from datasheet)
y = [1 2 3 4]
x = [2.54 1.54 1.09 0.86]

polyfit(x, y, 2)