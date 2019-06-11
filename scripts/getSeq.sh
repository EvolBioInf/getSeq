./getSeq -s '_1' ../data/test.fasta > tmp.out
DIFF=$(diff tmp.out ../data/getSeq.out)
if [ "$DIFF" == "" ] 
then
    printf "Test(getSeq)\tpass\n"
else
    printf "Test(getSeq)\tfail\n"
    echo ${DIFF}
fi

rm tmp.out
