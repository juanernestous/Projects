
function [h_impulse, h_t_air] = do_jump_analyses(jumpdata);
s_rate = 1000; % Hz, sampling rate of the force plate
del_time = 1/s_rate; % s, change in time based on the sampling rate

%% plot the GRF for the jump (x = time, y = GRF)in subplot(1,2,1)

time = jumpdata.time; % Time data
GRF = jumpdata.GRF_Z; % GRF data


% Identify indices where GRF < 30 (in air)
idx_air = find(GRF < 30);


% Calculate time in the air
t_air = del_time * (idx_air(length(idx_air))-idx_air(1)); % Total time in air


% Calculate body weight (mean GRF for the first ~1 second)
BW = mean(GRF(1:1000)); % N

% Calculate body mass (F = ma, a = g)
g = 9.81; % m/s^2
mass = BW / g; % kg

% Calculate acceleration-time curve
accel = (GRF - BW) / mass;

% Find takeoff index (last point before air)
idx_takeoff = idx_air(1) - 1;

% Calculate takeoff velocity using impulse-momentum approach
v_takeoff = trapz(accel(1:idx_takeoff)) * del_time; % m/s

% Calculate height using impulse-momentum approach
h_impulse = (v_takeoff^2) / (2 * g); % m
disp(['Height (Impulse-Momentum): ', num2str(h_impulse), ' m']);

% % Calculate height using time in air approach
h_t_air = (g * (t_air / 2)^2) / 2; % m
disp(['Height (Time in Air): ', num2str(h_t_air), ' m']);
