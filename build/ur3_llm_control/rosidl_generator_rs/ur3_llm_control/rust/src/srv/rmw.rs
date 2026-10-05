#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "ur3_llm_control__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur3_llm_control__srv__ExecuteSkill_Request() -> *const std::ffi::c_void;
}

#[link(name = "ur3_llm_control__rosidl_generator_c")]
extern "C" {
    fn ur3_llm_control__srv__ExecuteSkill_Request__init(msg: *mut ExecuteSkill_Request) -> bool;
    fn ur3_llm_control__srv__ExecuteSkill_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteSkill_Request>, size: usize) -> bool;
    fn ur3_llm_control__srv__ExecuteSkill_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteSkill_Request>);
    fn ur3_llm_control__srv__ExecuteSkill_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteSkill_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteSkill_Request>) -> bool;
}

// Corresponds to ur3_llm_control__srv__ExecuteSkill_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteSkill_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub skill: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub object: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone: rosidl_runtime_rs::String,

}



impl Default for ExecuteSkill_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur3_llm_control__srv__ExecuteSkill_Request__init(&mut msg as *mut _) {
        panic!("Call to ur3_llm_control__srv__ExecuteSkill_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteSkill_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__ExecuteSkill_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__ExecuteSkill_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__ExecuteSkill_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteSkill_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteSkill_Request where Self: Sized {
  const TYPE_NAME: &'static str = "ur3_llm_control/srv/ExecuteSkill_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur3_llm_control__srv__ExecuteSkill_Request() }
  }
}


#[link(name = "ur3_llm_control__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur3_llm_control__srv__ExecuteSkill_Response() -> *const std::ffi::c_void;
}

#[link(name = "ur3_llm_control__rosidl_generator_c")]
extern "C" {
    fn ur3_llm_control__srv__ExecuteSkill_Response__init(msg: *mut ExecuteSkill_Response) -> bool;
    fn ur3_llm_control__srv__ExecuteSkill_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteSkill_Response>, size: usize) -> bool;
    fn ur3_llm_control__srv__ExecuteSkill_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteSkill_Response>);
    fn ur3_llm_control__srv__ExecuteSkill_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteSkill_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteSkill_Response>) -> bool;
}

// Corresponds to ur3_llm_control__srv__ExecuteSkill_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteSkill_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub status: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for ExecuteSkill_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur3_llm_control__srv__ExecuteSkill_Response__init(&mut msg as *mut _) {
        panic!("Call to ur3_llm_control__srv__ExecuteSkill_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteSkill_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__ExecuteSkill_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__ExecuteSkill_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__ExecuteSkill_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteSkill_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteSkill_Response where Self: Sized {
  const TYPE_NAME: &'static str = "ur3_llm_control/srv/ExecuteSkill_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur3_llm_control__srv__ExecuteSkill_Response() }
  }
}


#[link(name = "ur3_llm_control__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur3_llm_control__srv__SetAttachment_Request() -> *const std::ffi::c_void;
}

#[link(name = "ur3_llm_control__rosidl_generator_c")]
extern "C" {
    fn ur3_llm_control__srv__SetAttachment_Request__init(msg: *mut SetAttachment_Request) -> bool;
    fn ur3_llm_control__srv__SetAttachment_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetAttachment_Request>, size: usize) -> bool;
    fn ur3_llm_control__srv__SetAttachment_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetAttachment_Request>);
    fn ur3_llm_control__srv__SetAttachment_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetAttachment_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetAttachment_Request>) -> bool;
}

// Corresponds to ur3_llm_control__srv__SetAttachment_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetAttachment_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub action: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub object: rosidl_runtime_rs::String,

}



impl Default for SetAttachment_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur3_llm_control__srv__SetAttachment_Request__init(&mut msg as *mut _) {
        panic!("Call to ur3_llm_control__srv__SetAttachment_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetAttachment_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__SetAttachment_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__SetAttachment_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__SetAttachment_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetAttachment_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetAttachment_Request where Self: Sized {
  const TYPE_NAME: &'static str = "ur3_llm_control/srv/SetAttachment_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur3_llm_control__srv__SetAttachment_Request() }
  }
}


#[link(name = "ur3_llm_control__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur3_llm_control__srv__SetAttachment_Response() -> *const std::ffi::c_void;
}

#[link(name = "ur3_llm_control__rosidl_generator_c")]
extern "C" {
    fn ur3_llm_control__srv__SetAttachment_Response__init(msg: *mut SetAttachment_Response) -> bool;
    fn ur3_llm_control__srv__SetAttachment_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetAttachment_Response>, size: usize) -> bool;
    fn ur3_llm_control__srv__SetAttachment_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetAttachment_Response>);
    fn ur3_llm_control__srv__SetAttachment_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetAttachment_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetAttachment_Response>) -> bool;
}

// Corresponds to ur3_llm_control__srv__SetAttachment_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetAttachment_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for SetAttachment_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur3_llm_control__srv__SetAttachment_Response__init(&mut msg as *mut _) {
        panic!("Call to ur3_llm_control__srv__SetAttachment_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetAttachment_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__SetAttachment_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__SetAttachment_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__SetAttachment_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetAttachment_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetAttachment_Response where Self: Sized {
  const TYPE_NAME: &'static str = "ur3_llm_control/srv/SetAttachment_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur3_llm_control__srv__SetAttachment_Response() }
  }
}


#[link(name = "ur3_llm_control__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur3_llm_control__srv__GetWorldState_Request() -> *const std::ffi::c_void;
}

#[link(name = "ur3_llm_control__rosidl_generator_c")]
extern "C" {
    fn ur3_llm_control__srv__GetWorldState_Request__init(msg: *mut GetWorldState_Request) -> bool;
    fn ur3_llm_control__srv__GetWorldState_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetWorldState_Request>, size: usize) -> bool;
    fn ur3_llm_control__srv__GetWorldState_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetWorldState_Request>);
    fn ur3_llm_control__srv__GetWorldState_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetWorldState_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetWorldState_Request>) -> bool;
}

// Corresponds to ur3_llm_control__srv__GetWorldState_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetWorldState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetWorldState_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur3_llm_control__srv__GetWorldState_Request__init(&mut msg as *mut _) {
        panic!("Call to ur3_llm_control__srv__GetWorldState_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetWorldState_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__GetWorldState_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__GetWorldState_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__GetWorldState_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetWorldState_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetWorldState_Request where Self: Sized {
  const TYPE_NAME: &'static str = "ur3_llm_control/srv/GetWorldState_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur3_llm_control__srv__GetWorldState_Request() }
  }
}


#[link(name = "ur3_llm_control__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur3_llm_control__srv__GetWorldState_Response() -> *const std::ffi::c_void;
}

#[link(name = "ur3_llm_control__rosidl_generator_c")]
extern "C" {
    fn ur3_llm_control__srv__GetWorldState_Response__init(msg: *mut GetWorldState_Response) -> bool;
    fn ur3_llm_control__srv__GetWorldState_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetWorldState_Response>, size: usize) -> bool;
    fn ur3_llm_control__srv__GetWorldState_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetWorldState_Response>);
    fn ur3_llm_control__srv__GetWorldState_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetWorldState_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetWorldState_Response>) -> bool;
}

// Corresponds to ur3_llm_control__srv__GetWorldState_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetWorldState_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub objects: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub locations: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub held_object: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub camera_ready: bool,

}



impl Default for GetWorldState_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur3_llm_control__srv__GetWorldState_Response__init(&mut msg as *mut _) {
        panic!("Call to ur3_llm_control__srv__GetWorldState_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetWorldState_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__GetWorldState_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__GetWorldState_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur3_llm_control__srv__GetWorldState_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetWorldState_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetWorldState_Response where Self: Sized {
  const TYPE_NAME: &'static str = "ur3_llm_control/srv/GetWorldState_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur3_llm_control__srv__GetWorldState_Response() }
  }
}






#[link(name = "ur3_llm_control__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ur3_llm_control__srv__ExecuteSkill() -> *const std::ffi::c_void;
}

// Corresponds to ur3_llm_control__srv__ExecuteSkill
#[allow(missing_docs, non_camel_case_types)]
pub struct ExecuteSkill;

impl rosidl_runtime_rs::Service for ExecuteSkill {
    type Request = ExecuteSkill_Request;
    type Response = ExecuteSkill_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ur3_llm_control__srv__ExecuteSkill() }
    }
}




#[link(name = "ur3_llm_control__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ur3_llm_control__srv__SetAttachment() -> *const std::ffi::c_void;
}

// Corresponds to ur3_llm_control__srv__SetAttachment
#[allow(missing_docs, non_camel_case_types)]
pub struct SetAttachment;

impl rosidl_runtime_rs::Service for SetAttachment {
    type Request = SetAttachment_Request;
    type Response = SetAttachment_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ur3_llm_control__srv__SetAttachment() }
    }
}




#[link(name = "ur3_llm_control__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ur3_llm_control__srv__GetWorldState() -> *const std::ffi::c_void;
}

// Corresponds to ur3_llm_control__srv__GetWorldState
#[allow(missing_docs, non_camel_case_types)]
pub struct GetWorldState;

impl rosidl_runtime_rs::Service for GetWorldState {
    type Request = GetWorldState_Request;
    type Response = GetWorldState_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ur3_llm_control__srv__GetWorldState() }
    }
}


