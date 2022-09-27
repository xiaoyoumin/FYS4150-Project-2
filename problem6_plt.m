v10=load('eigenvectors_10.txt');
v100=load('eigenvectors_100.txt');
eigv10=load('eigenvalues_10.txt');
eigv100=load('eigenvalues_100.txt');

v10=[[0,0,0];v10;[0,0,0]];
v100=[[0,0,0];v100;[0,0,0]];

for i=1:3
    figure (i)
    plot(0:1/10:1,v10(:,i))
    title(['n = 10, correspond eigenvalue, lambda = ' eigv10(i)]);
    xlabel('x_hat') 
    ylabel('v') 
end

for i=4:6
    figure (i)
    plot(0:1/100:1,v100(:,i-3))
    title(['n = 100, correspond eigenvalue, lambda = ' eigv100(i-3)]);
    xlabel('x_hat') 
    ylabel('v') 
end