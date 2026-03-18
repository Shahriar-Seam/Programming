"""
LZW Compression + Decompression Table Generator
"""

def seq_str(seq):
    return "-".join(str(v) for v in seq)

def print_table(rows, headers):
    col_widths = [len(h) for h in headers]
    for row in rows:
        for j, cell in enumerate(row):
            col_widths[j] = max(col_widths[j], len(str(cell)))

    def fmt_row(cells):
        return " | ".join(str(c).center(col_widths[i]) for i, c in enumerate(cells))

    separator = "-+-".join("-" * w for w in col_widths)
    print(fmt_row(headers))
    print(separator)
    for row in rows:
        print(fmt_row(row))


def lzw_encode(pixel_sequence):
    dictionary = {(v,): v for v in range(256)}
    next_code = 256

    rows = []
    pixels = list(pixel_sequence)
    encoded_output = []
    i = 0

    current_seq = (pixels[i],)
    rows.append(("", str(pixels[i]), "", "", ""))
    i += 1

    while i < len(pixels):
        pixel = pixels[i]
        extended_seq = current_seq + (pixel,)

        if extended_seq in dictionary:
            rows.append((seq_str(current_seq), str(pixel), "", "", ""))
            current_seq = extended_seq
        else:
            code = dictionary[current_seq]
            encoded_output.append(code)
            rows.append((seq_str(current_seq), str(pixel), str(code), str(next_code), seq_str(extended_seq)))
            dictionary[extended_seq] = next_code
            next_code += 1
            current_seq = (pixel,)

        i += 1

    # Final sequence
    code = dictionary[current_seq]
    encoded_output.append(code)
    rows.append((seq_str(current_seq), "", str(code), "", ""))

    return encoded_output, rows


def lzw_decode(encoded):
    dictionary = {v: (v,) for v in range(256)}
    next_code = 256

    rows = []
    decoded_output = []

    # First code
    code = encoded[0]
    current_seq = dictionary[code]
    decoded_output.extend(current_seq)
    rows.append((str(code), seq_str(current_seq), "", "", ""))

    for i in range(1, len(encoded)):
        code = encoded[i]
        prev_seq = current_seq

        if code in dictionary:
            current_seq = dictionary[code]
        else:
            # Special case: code not yet in dictionary
            current_seq = prev_seq + (prev_seq[0],)

        decoded_output.extend(current_seq)

        # Add new dictionary entry: prev_seq + first pixel of current_seq
        new_entry = prev_seq + (current_seq[0],)
        if next_code not in dictionary:
            dictionary[next_code] = new_entry
            rows.append((str(code), seq_str(current_seq), str(next_code), seq_str(new_entry), seq_str(decoded_output[-len(current_seq):])))
            next_code += 1
        else:
            rows.append((str(code), seq_str(current_seq), "", "", ""))

    return decoded_output, rows


if __name__ == "__main__":
    image = [
        [23, 2, 30, 23, 2, 30],
        [23, 2, 30, 23, 2, 30],
        [23, 2, 30, 23, 2, 30],
        [23, 2, 30, 23, 2, 30],
        [23, 2, 30, 23, 2, 30],
        [23, 2, 30, 23, 2, 30],
    ]

    pixel_sequence = [pixel for row in image for pixel in row]

    print("=" * 80)
    print("ORIGINAL PIXEL SEQUENCE")
    print("=" * 80)
    print(pixel_sequence)
    print(f"Total pixels: {len(pixel_sequence)}")

    # ENCODE
    print("\n" + "=" * 80)
    print("ENCODING TABLE")
    print("=" * 80)
    encoded, enc_rows = lzw_encode(pixel_sequence)
    enc_headers = [
        "Currently Recognized Sequence",
        "Pixel Being Processed",
        "Encoded Output",
        "Dictionary Location (Code Word)",
        "Dictionary Entry",
    ]
    print_table(enc_rows, enc_headers)

    print("\n" + "=" * 80)
    print("COMPRESSED CODE ARRAY")
    print("=" * 80)
    print(encoded)
    print(f"Total codes: {len(encoded)}  (compressed from {len(pixel_sequence)} pixels)")
    ratio = (1 - len(encoded) / len(pixel_sequence)) * 100
    print(f"Compression: {ratio:.1f}% reduction")

    # DECODE
    print("\n" + "=" * 80)
    print("DECODING TABLE")
    print("=" * 80)
    decoded, dec_rows = lzw_decode(encoded)
    dec_headers = [
        "Code Received",
        "Decoded Output",
        "New Dict Location",
        "New Dict Entry",
        "Pixels Output",
    ]
    print_table(dec_rows, dec_headers)

    print("\n" + "=" * 80)
    print("DECODED PIXEL SEQUENCE")
    print("=" * 80)
    print(decoded)
    print(f"Total pixels: {len(decoded)}")
    print(f"Lossless match: {pixel_sequence == decoded}")