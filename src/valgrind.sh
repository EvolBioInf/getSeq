valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all --log-file="getSeq.val" --dsymutil=yes ./getSeq -s '_1' ../data/test.fasta > /dev/null


