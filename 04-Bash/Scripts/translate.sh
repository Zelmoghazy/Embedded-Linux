#!/bin/bash

word=$(xclip -o -sel clip)

target_lang="ar"

translate_url="https://translate.google.com/?sl=auto&tl=$target_lang&text=$word&op=translate"

xdg-open "$translate_url"
