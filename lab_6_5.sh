find $2 -type f -exec sh -c 'fileName="{}"; mv "$fileName" "${fileName}.unu"' \;
mv $2 $1
