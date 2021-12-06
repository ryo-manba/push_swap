echo "=====3test====="
for ((i=0; i<100; i++)); do ARG=$(jot -r -s " " 3 -2147483648 2147483647); ./push_swap $ARG | ./checker $ARG; done
for ((i=0; i<100; i++)); do ARG=$(jot -r -s " " 3 -2147483648 2147483647); ./push_swap $ARG | wc -l; done > ans3.txt
sort ans3.txt

echo "=====5test====="
for ((i=0; i<100; i++)); do ARG=$(jot -r -s " " 5 -2147483648 2147483647); ./push_swap $ARG | ./checker $ARG; done
for ((i=0; i<100; i++)); do ARG=$(jot -r -s " " 5 -2147483648 2147483647); ./push_swap $ARG | wc -l; done > ans5.txt
sort ans5.txt

echo "=====100test====="
for ((i=0; i<100; i++)); do ARG=$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $ARG | ./checker $ARG; done
for ((i=0; i<100; i++)); do ARG=$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $ARG | wc -l; done > ans100.txt
sort ans100.txt

echo "=====500test====="
for ((i=0; i<100; i++)); do ARG=$(jot -r -s " " 500 -2147483648 2147483647); ./push_swap $ARG | ./checker $ARG; done
for ((i=0; i<100; i++)); do ARG=$(jot -r -s " " 500 -2147483648 2147483647); ./push_swap $ARG | wc -l; done > ans500.txt
sort ans500.txt
echo "=====3test====="
awk '{sum+=$1}NR==1{max=$1}NR==1{min=$1}{if($1 > max)max=$1}{if($1<min)min=$1} END{print NR "tests", "\navg = "sum/NR, "\nmax = "max, "\nmin = "min}' ans3.txt
echo "=====5test====="
awk '{sum+=$1}NR==1{max=$1}NR==1{min=$1}{if($1 > max)max=$1}{if($1<min)min=$1} END{print NR "tests", "\navg = "sum/NR, "\nmax = "max, "\nmin = "min}' ans5.txt
echo "=====100test====="
awk '{sum+=$1}NR==1{max=$1}NR==1{min=$1}{if($1 > max)max=$1}{if($1<min)min=$1} END{print NR "tests", "\navg = "sum/NR, "\nmax = "max, "\nmin = "min}' ans100.txt
echo "=====500test====="
awk '{sum+=$1}NR==1{max=$1}NR==1{min=$1}{if($1 > max)max=$1}{if($1<min)min=$1} END{print NR "tests", "\navg = "sum/NR, "\nmax = "max, "\nmin = "min}' ans500.txt
rm ans3.txt
rm ans5.txt
rm ans100.txt
rm ans500.txt