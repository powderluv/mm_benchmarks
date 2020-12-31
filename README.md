# mm_benchmarks

BUILD
```
mkdir b; cd b;
EIGEN3_INCLUDE_DIR=/Users/nodai/github/eigen cmake .. -GNinja
ninja

```

RUN

```
nodai@macbook-pro-2 b % ./eigen_mm_benchmark
nodai@macbook-pro-2 b % ./neon-gemm-kernel-benchmark

```


TODO:
ruy integration


CREDITS:

neon-gemm-kernel-benchmark.cc taken from https://github.com/google/gemmlowp and fixed crash in INT4

