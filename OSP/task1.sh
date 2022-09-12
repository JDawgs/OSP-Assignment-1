
# remove punctuation
sed -e "s/\([[:punct:]]\)//g" > tempfile1.txt
# Filter words above length of 16 and below length of 3
sed -r 's/\b\w{16,}\s?\b//g' < tempfile1.txt > tempfile2.txt
sed -r 's/\b\w{,2}\s?\b//g' < tempfile2.txt > tempfile1.txt
# Remove Whitespaces
sed -e "/^$/d" < tempfile1.txt > tempfile2.txt 
# Sort file
sort -u tempfile2.txt > tempfile1.txt