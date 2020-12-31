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


ruy results:
THREADS=8 RUY_BENCHMARK_CUBIC=1 NOEXT=1 PATHS=f0 ./build_tools/third_party/ruy/benchmark_f32_f32_f32_f32
size,kNeon:Gop/s,kNeonDotprod:Gop/s
16,32.4,32
24,53.27,52.75
32,65.25,65.17
48,125.5,124
64,45.57,47.24
96,75.85,78.76
128,134.2,134.2
192,202.6,211.1
256,253.5,249.9
384,286.5,287.1
512,359.9,364.6
768,356,354
1024,430.4,424.6
1536,470.1,463.5
2048,470.7,469.2
3072,459,456.4
4096,454.1,454.3
Covered paths: kNeon, kNeonDotprod



CREDITS:

neon-gemm-kernel-benchmark.cc taken from https://github.com/google/gemmlowp and fixed crash in INT4

