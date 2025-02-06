function sway_length = calc_sway_length(COPx, COPy)
    %COP delta
    dx = diff(COPx);
    dy = diff(COPy);

    %distance between points
    distances = sqrt(dx.^2 + dy.^2);

    %sum of distances
    sway_length = sum(distances);
end