#PAUTLEN 1361 (2019). PAREJA 3: David Palomo Marcos, Pablo Sanchez Redondo
echo $'>> Running make:'
make
echo $'\n>> Running tests:'
i=1
c=0
for f in tests/in*
do
o="tests/out${i}.txt"
r="tests/out${i}_bad.txt"
./prueba_tabla $f $r
cmp -s $r $o && let c=${c}+1 && rm $r || echo "test${i} FAILED (check $r)"
let i=${i}+1
done
let i=${i}-1
echo "$c/$i OK"
