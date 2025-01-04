#include <iostream>
#include "crtp.hpp"
#include "dynPolymorphic.hpp"
#include <benchmark/benchmark.h>
#include <chrono> 
using namespace std::chrono;

/*
PRETTY_NAME="Ubuntu 22.04.5 LTS"
NAME="Ubuntu"
VERSION_ID="22.04"
VERSION="22.04.5 LTS (Jammy Jellyfish)"
VERSION_CODENAME=jammy
ID=ubuntu
ID_LIKE=debian
HOME_URL="https://www.ubuntu.com/"
SUPPORT_URL="https://help.ubuntu.com/"
BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
UBUNTU_CODENAME=jammy
*/

static void BM_STATIC_POLY_CRTP(benchmark::State& state) {
	SpecificCRTP* specificcrtp = new SpecificCRTP;
  for (auto _ : state)
    specificcrtp->doSomething();
}
// Register the function as a benchmark
BENCHMARK(BM_STATIC_POLY_CRTP);

// Define another benchmark
static void BM_DYNAMIC_POLY(benchmark::State& state) {
  DynPolymorphic* sdp = new SpecificDynPolymorphic;
  for (auto _ : state)
    sdp->doSomething();
}
BENCHMARK(BM_DYNAMIC_POLY);

BENCHMARK_MAIN();




// g++ main.cpp -std=c++11 -isystem ../benchmark/include  -L/root/benchmark/build/src -lbenchmark -lpthread -o mybenchmark
