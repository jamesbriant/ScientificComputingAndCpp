%This script plots a matrix stored in a text file to the screen
%and saves it to a .jpg file for inclusion in your Class Test 
%submission.
%
%You can change the names of the inputs/outputs as you wish.

clear all
close all
Z = load("matrix.dat"); %Change the filename if required

Z = flip(Z); %Reverse the rows
[n,m] = size(Z);

Z = [Z;zeros(1,m)]; %Pad the matrix
Z = [Z zeros(n+1,1)];

s = pcolor(Z); %Plot the matrix
axis off
axis square

%Export to jpg
saveas(s,'matrix.jpg') %Change the filename if required