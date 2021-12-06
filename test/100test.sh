echo "=====100test====="
for ((i=0; i<100; i++)); do ARG=$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $ARG | ./checker $ARG; done
for ((i=0; i<100; i++)); do ARG=$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $ARG | wc -l; done > ans.txt
sort ans.txt
awk '{sum+=$1}NR==1{max=$1}NR==1{min=$1}{if($1 > max)max=$1}{if($1<min)min=$1} END{print NR "tests", "\navg = "sum/NR, "\nmax = "max, "\nmin = "min}' ans.txt
rm ans.txt