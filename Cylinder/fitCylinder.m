clc
clear
p_fos = 3; % recommended factor of safety for pressure vessels is between 3.0 - 6.0
D = 800; % internal diameter 800mm
S = 1950 * 10^6; % Ultimate tensile strength for Fiber glass
u = 0.23; % poissons ratio for fiber glass
t = [0,0.001]; % 1000th of a meter starting thickness
P = [0,0];
figure(1);
plot(P,t,"x");
i = 2;
while(1)
    i = i+1;
    % internal pressure
    P(i)= (S*((((2*t(i-1)/D)+1)^2)-1))/((1-2*u)+(1+u)*(((2*t(i-1)/D)+1)^2));
    t_fos = S/P(i); % factor of safety(fos)
    % if fos is below the recommended value,break
    if(t_fos  < p_fos) 
        break
    end
    hold on
    t(i)= t(i-1)+0.01; % 0.01 increment thickness
    plot(P(1:i),t(1:i),"x");
end

title("Thickness against Internal Pressure")
ylabel("Thickness(m)");
xlabel("Pressure(Pa)")
legend("Shell Thickness vs internal pressure")
hold off