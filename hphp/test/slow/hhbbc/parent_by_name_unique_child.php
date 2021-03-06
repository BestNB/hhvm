<?hh

if (__hhvm_intrinsics\launder_value(true)) {
  require_once 'parent_by_name_unique_child.1.inc';
} else {
  require_once 'parent_by_name_unique_child.2.inc';
}

class D extends C {
  // incompatible with the second version of C
  const type INCOMPATIBLE = int;

  public static function printStuff() {
    echo C::C['c'];
  }
}

<<__EntryPoint>>
function test() { D::printStuff(); }
