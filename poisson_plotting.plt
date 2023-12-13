set terminal svg size 400, 300 enhanced fname "arial"
# set output "Aufgabe_1c_hist.svg"
plot "histpoi.txt" using 1:2 smooth freq with boxes title "data", \
    "" using 1:3 smooth freq with boxes title "simulation"
