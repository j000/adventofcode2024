fs = import('fs')

day2input = fs.copyfile('input', 'input')

day2exe = executable('day2',
  'day2.cpp',
  )

run_target('day2_run',
  command: [day2exe, day2input],
  )

day2bexe = executable('day2b',
  'day2b.cpp',
  )

run_target('day2b_run',
  command: [day2bexe, day2input],
  )

# vim: set et ts=2 sw=2:
