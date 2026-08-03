# Product reference build

The product reference source is maintained in Markdown under `chapters/`. Document
metadata and chapter order are defined in `book.yml`.

## Local build

Requirements:

- Pandoc
- WeasyPrint

Run from the repository root:

```bash
./tools/product-reference/build.sh
```

Generated files are written to `build/product-reference/`:

```text
unit_product_reference_v_0_1_0_i2c_mpu6050_6_axis_imu.md
unit_product_reference_v_0_1_0_i2c_mpu6050_6_axis_imu.docx
unit_product_reference_v_0_1_0_i2c_mpu6050_6_axis_imu.html
unit_product_reference_v_0_1_0_i2c_mpu6050_6_axis_imu.pdf
```

The Markdown chapters are the source of truth. Product values and pin mappings
must be taken from the released files in `hardware/`, the manufacturing
BOM, or other supplied product sources. Do not infer module electrical
limits from the rating of an individual BOM component.

Unvalidated firmware is intentionally omitted from the generated reference,
and missing module-level characteristics are marked as pending validation.
