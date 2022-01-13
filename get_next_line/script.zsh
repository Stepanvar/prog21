cd texts
./fillfile
rm -rf ../res.txt
rm -rf ../diff/*.txt
for var in $(ls *.txt)
do
cd ..
mkdir -p diff
touch 'diff/diff_'$var
echo $var
for buf in 1 6 42 9999999
do
make fclean
make AFL="-D BUFFER_SIZE=$buf"
./getnl.exe 'texts/'$var > 'diff/diff_'$var
echo $var >> res.txt
echo BS=$buf >> res.txt
diff 'texts/'$var 'diff/diff_'$var >> res.txt
done
cd texts
done
