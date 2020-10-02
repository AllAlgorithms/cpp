  long fact_l(int n) {
      long out = 1;
      for(int i = n; i > 1; i++) {
          out *= i;
      }

      return out;
  }
