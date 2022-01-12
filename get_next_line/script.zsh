cd ~/prog21/get_next_line/texts
#./fillfile
rm -rf ../res.txt
rm -rf ../diff/*.txt
for var in $(ls *.txt)
do
cd ..
mkdir -p diff
touch 'diff/diff_'$var
echo $var
./getnl.out 'texts/'$var > 'diff/diff_'$var
echo $var >> res.txt
diff 'texts/'$var 'diff/diff_'$var >> res.txt
cd ~/prog21/get_next_line/texts
done
