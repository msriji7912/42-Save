#!/bin/bash

# Génère les permutations récursivement
permute () {
    local prefix="$1"
    local rest="$2"

    if [ -z "$rest" ]; then
        test_case "$prefix"
        return
    fi

    for i in $(seq 0 $((${#rest}-1))); do
        permute \
            "$prefix ${rest:$i:1}" \
            "${rest:0:$i}${rest:$i+1}"
    done
}

# Test une permutation
test_case () {
    local nums=$(echo "$1" | xargs)

    # Lance push_swap et checker
    result=$(./push_swap $nums | ./checker_linux $nums)

    if [ "$result" != "OK" ]; then
        echo "❌ KO pour: $nums"
        exit 1
    else
        echo "✅ OK : $nums"
    fi
}

# ===== CONFIG =====
NUMBERS="12"   # mets 12345 pour 5 nombres
# ==================

permute "" "$NUMBERS"

echo "🎉 Toutes les permutations sont OK"
