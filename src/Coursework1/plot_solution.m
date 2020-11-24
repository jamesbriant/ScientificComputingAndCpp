%This script reads in a file called mesh_solution.dat,
%plots the solution and saves to a jpg file in the 
%current directory.
%
%The input file should have two columns, the first being
%the nodes of the mesh, the second being the approximate
%solution at those nodes

%Read data (change filename if required)
Z = load("mesh_solution.dat");

%Plot solution
h = plot(Z(:,1),Z(:,2));
xlabel("x");
ylabel("u");

%Export to jpg (change filename if required)
print('solution.jpg','-djpeg')
