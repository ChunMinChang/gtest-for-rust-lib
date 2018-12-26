sh clean.sh && sh build.sh

cd build

make

./test_sanity

./test_rust