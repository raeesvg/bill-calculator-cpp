#!/usr/bin/env bash
set -e
make
echo "Running premium service test..."
./bin/billcalc <<'EOF'
2002
p
80
30
EOF
# Here: dayMinutes=80 (5 extra -> R5), nightMinutes=30 (no charge)
# Total bill = R250 + 5 = R255.00
