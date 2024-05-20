#!/bin/python3

import sys
import re


def replace_timestamps(input_text):
    timestamp_pattern = r"\[\d{8}_\d{6}\]"
    output_text = re.sub(timestamp_pattern, "[19920104_091532]", input_text)
    return output_text


def main():
    input_text = sys.stdin.read()
    output_text = replace_timestamps(input_text)
    print(output_text, end="")


if __name__ == "__main__":
    main()
