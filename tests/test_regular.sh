#!/usr/bin/env bash
set -e
make
echo "Running regular service test..."
./bin/billcalc <<'EOF'
1001
r
60
EOF
# Expected: base R100 + (60 - 50)*2 = 100 + 20 = R120.00
