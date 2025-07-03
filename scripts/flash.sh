#!/usr/bin/env bash
set -euo pipefail

HERE=$(dirname "$0")
cd "${HERE}/.."

qmk flash -kb ferris/sweep ferris_sweep_christianwaldmann.hex

