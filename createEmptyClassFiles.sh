#!/bin/sh
cat _.txt > $1.hh 
echo "#ifndef "$1"_hh" >> $1.hh
echo "#define "$1"_hh" >> $1.hh
echo "" >> $1.hh	# blank line
echo "class "$1 >> $1.hh
echo "{" >> $1.hh
echo "  public:" >> $1.hh
echo "    "$1"();" >> $1.hh
echo "    ~"$1"();" >> $1.hh
echo "" >> $1.hh	# blank line
echo "  private:" >> $1.hh
echo "};" >> $1.hh
echo "#endif" >> $1.hh

cat _.txt > $1.cc 
echo -e "#include \"./"$1".hh\"" >> $1.cc
echo "" >> $1.cc	# blank line
echo $1"::"$1"()" >> $1.cc
echo "{}" >> $1.cc
echo "" >> $1.cc	# blank line
echo $1"::~"$1"()" >> $1.cc
echo "{}" >> $1.cc

