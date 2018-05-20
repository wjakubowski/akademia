#pragma once

void report_to_stdout(bool with_bonus, bool include_tax, bool with_super_bonus);

void report_to_file(const char* file, bool with_bonus, bool include_tax, bool with_super_bonus);
