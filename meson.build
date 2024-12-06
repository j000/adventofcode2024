project('adventofcode2024',
  'cpp',
  version: '0.0.1',
  default_options: [
    'cpp_std=c++20',
    'b_lto=true',
    'b_staticpic=true',
    'b_pie=true',
    'warning_level=3',
    'bindir=',
    'libdir=lib',
    ],
  meson_version: '>=1.6.0',
  )

add_project_link_arguments('-Wl,--gc-sections', language: 'cpp')
if get_option('buildtype') == 'debug'
  add_project_arguments('-ggdb3', language: 'cpp')
else
  add_project_arguments('-D_FORTIFY_SOURCE=2', language: 'cpp')
endif


subdir('day1')
subdir('day2')
subdir('day3')


# vim: set et ts=2 sw=2:
