package FFI::Platypus::Lang::Rust;

use strict;
use warnings;
use FFI::Platypus;

our $VERSION = '0.01';

=head1 NAME

FFI::Platypus::Lang::Rust - Documentation and tools for using Platypus with
the Rust programming language

=head1 SYNOPSIS

 use FFI::Platypus;
 my $ffi = FFI::Platypus->new;
 $ffi->with('Rust');

=head1 DESCRIPTION

This module provides some hooks for Platypus to interact with the 
Rust programming language.

=cut

sub primitive_type_map
{
  {
    u8       => 'uint8',
    u16      => 'uint16',
    u32      => 'uint32',
    u64      => 'uint64',
    i8       => 'sint8',
    i16      => 'sint16',
    i32      => 'sint32',
    i64      => 'sint64',
    binary32 => 'float',    # need to check this is right
    binary64 => 'double',   #  "    "  "     "    "  "
    f32      => 'float',
    f64      => 'double',
    usize    => do { FFI::Platypus->type_meta('size_t')->{ffi_type} },
    isize    => do {
      my $ffi_type = FFI::Platypus->type_meta('size_t')->{ffi_type};
      $ffi_type =~ s{^u}{s};
      $ffi_type;
    },
  },
}

1;