project(
  'cdf_ori_readall',
  'cpp',
  meson_version: '>= 0.63.0',
  default_options : ['warning_level=3', 'cpp_std=c++17', 'default_library=static'],
  license : 'GPL3'
)

cdfpp_dep = dependency('cdfpp')
fmt_dep = dependency('fmt')
argparse_dep = dependency('argparse')

cdf_ori_readall = executable('cdf_ori_readall', 'main.cpp', dependencies: [cdfpp_dep, fmt_dep, argparse_dep])

