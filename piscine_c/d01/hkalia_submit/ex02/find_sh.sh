find . -type f -name "*.sh" -print | sed "s|./||" | cut -d "." -f 1 | sed "s|^.*\/||"
