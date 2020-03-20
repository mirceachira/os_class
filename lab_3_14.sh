echo "enter first file path: "
read file_a
echo "enter second file path: "
read file_b
diff $file_a $file_b -y --suppress-common-lines | head -n 5
