#!/usr/bin/env bash
set -euo pipefail

HERE=$(dirname "$0")
cd "${HERE}/.."

# Move keymap to expected location
cp -r ./keymaps/christianwaldmann ~/qmk_firmware/keyboards/ferris/keymaps

# Compile
qmk compile -kb ferris/sweep -km christianwaldmann

# Move file here
mv ~/qmk_firmware/ferris_sweep_christianwaldmann.hex .

