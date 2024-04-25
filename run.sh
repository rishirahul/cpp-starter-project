# -S option allow to generate cmake build directory from src directory
# -B options help is passing build directory path
cmake -S . -B /tmp/build -DBUILD_DOC=TRUE -DBUILD_TEST=TRUE
cmake --build /tmp/build
echo "running test"
cd /tmp/build/test
ctest
cd -
