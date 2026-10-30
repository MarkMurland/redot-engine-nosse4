import os

# SCons may initialize the project environment later than this file is read.
# Keep the branch resilient by falling back to a minimal environment and CLI args.
if 'env' not in globals():
    env = Environment(ENV={'PATH': os.environ.get('PATH', '')})

arch = env.get('arch', ARGUMENTS.get('arch', 'x86_64'))

# Keep x86_64 on the SSE2 baseline for this branch and avoid forcing SSE4.2,
# SSSE3, or POPCNT flags that reject older 64-bit CPUs.
if arch == 'x86_64':
    compiler = str(env.get('CC', '')).lower()
    if 'cl' in compiler or 'clang-cl' in compiler or env.get('MSVC_VERSION'):
        env.Append(CCFLAGS=['/arch:SSE2'])
    else:
        env.Append(CCFLAGS=['-msse2'])
elif arch == 'x86_32':
    compiler = str(env.get('CC', '')).lower()
    if 'cl' in compiler or 'clang-cl' in compiler or env.get('MSVC_VERSION'):
        env.Append(CCFLAGS=['/arch:SSE2'])
    else:
        env.Append(CCFLAGS=['-msse2', '-mfpmath=sse', '-mstackrealign'])
