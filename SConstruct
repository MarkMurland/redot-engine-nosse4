# Set x86 CPU instruction sets to use by the compiler's autovectorization.
if env["arch"] == "x86_64":
    # x86_64 requires at least SSE2; avoid forcing newer ISA levels.
    if getattr(env, "msvc", False) and not methods.using_clang(env):
        env.Append(CCFLAGS=["/arch:SSE2"])
    else:
        env.Append(CCFLAGS=["-msse2"])
elif env["arch"] == "x86_32":
    # Keep 32-bit x86 conservative.
    if getattr(env, "msvc", False) and not methods.using_clang(env):
        env.Append(CCFLAGS=["/arch:SSE2"])
    else:
        env.Append(CCFLAGS=["-msse2", "-mfpmath=sse", "-mstackrealign"])
