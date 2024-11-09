#!/bin/bash
rm -r "libft-unit-test/"
rm -r "TripouilleTester/"
make fclean >/dev/null 2>&1 || true
rm -r "$0"
