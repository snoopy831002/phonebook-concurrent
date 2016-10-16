reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison with different num of threads'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.02]'output.txt' using 2:xtic(1) with histogram title '1 thread', \
'' using ($0-0.2):($2+0.001):2 with labels title '', \
'' using 3:xtic(1) with histogram title '2 thread'  , \
'' using ($0-0.04):($3+0.0015):3 with labels title '', \
'' using 4:xtic(1) with histogram title '4 thread'   , \
'' using ($0+0.01):($4+0.0025):4 with labels title'',\
'' using 5:xtic(1) with histogram title '8 thread'  , \
'' using ($0+0.2):($5+0.0021):5 with labels title ' ', \
'' using 6:xtic(1) with histogram title '16 thread', \
'' using ($0+0.45):($6+0.003):6 with labels title ' ', \
