long fib(int n) {
  assert n >= 2;
  if (n == 1 || n == 0) {
    return 1;
  }

  return fib(n - 2) + fin(n - 1);
}
